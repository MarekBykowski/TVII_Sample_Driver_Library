import csv
import os
from datetime import datetime

# File name paths
TVII_CHIP_LIST_CSV_FILE_WITH_REL_PATH = "tvii_chip_list.csv"
ODB_TEMPLATE_FILE_WITH_REL_PATH       = "flash_chips_fcr4tcm.odb.template"
ODB_OUTPUT_FILE_WITH_REL_PATH         = "..\\flash_chips_fcr4tcm.odb"


# Enables/Disables the output of some debug messages (e.g. the calculated flash addresses/gaps)
PRINT_DEBUG_MESSAGES = False  # Set True or False

# Chip definitions will be added at this line in the ODB template file
ODB_FILE_TEMPLATE_INSERTION_MARKER = "<<<SCRIPT_ADDS_TRAVEO_II_ENTRIES_HERE>>>"

# Each device will be visually separated in the ODB file by using following string
ODB_FILE_ENTRY_SEPARATOR           = 120 * "~"

# A template for a TVII device entry, with marker strings for the variable content
ENTRY_TEMPLATE = """\
  { cpu_name="<<<DESCRIPTION>>>";
    tvii_famid=<<<FAMILY_ID>>>; tvii_silid=<<<SILICON_ID>>>; dual_bank=false;
    geometry {
      { count=<<<CF_SECTOR_NUMBER_LARGE>>>; size="32 KB" }
      { count=<<<CF_SECTOR_NUMBER_SMALL>>>; size="8 KB" }
      { count=1; size="<<<GAP_CF_END_TO_SFLASH_START_KB>>> KB"; valid=false }
      { count=64; size="512" }
      { count=1; size="8160 KB"; valid=false }
      { count=64; size="512" }
    }
  }
  { cpu_name="<<<DESCRIPTION>>> | DualBank";
    tvii_famid=<<<FAMILY_ID>>>; tvii_silid=<<<SILICON_ID>>>; dual_bank=true;
    geometry {
      { count=<<<CF_SECTOR_NUMBER_LARGE_DB>>>; size="32 KB" }
      { count=<<<CF_SECTOR_NUMBER_SMALL_DB>>>; size="8 KB" }
      { count=1; size="<<<GAP_CF_LOWER_BANK_END_TO_UPPER_BANK_START_KB>>> KB"; valid=false }
      { count=<<<CF_SECTOR_NUMBER_LARGE_DB>>>; size="32 KB" }
      { count=<<<CF_SECTOR_NUMBER_SMALL_DB>>>; size="8 KB" }
      { count=1; size="<<<GAP_CF_END_DB_TO_SFLASH_START_KB>>> KB"; valid=false }
      { count=64; size="512" }
      { count=1; size="8160 KB"; valid=false }
      { count=64; size="512" }
    }
  }
  { cpu_name="<<<DESCRIPTION>>> | WorkFlash";
    tvii_famid=<<<FAMILY_ID>>>; tvii_silid=<<<SILICON_ID>>>; wflash=true; row_bytes=4; dual_bank=false;
    geometry {
      { count=<<<WF_SECTOR_NUMBER_LARGE>>>; size="2 KB" }
      { count=<<<WF_SECTOR_NUMBER_SMALL>>>; size="128" }
    }
  }
  { cpu_name="<<<DESCRIPTION>>> | WorkFlash | DualBank";
    tvii_famid=<<<FAMILY_ID>>>; tvii_silid=<<<SILICON_ID>>>; wflash=true; row_bytes=4; dual_bank=true;
    geometry {
      { count=<<<WF_SECTOR_NUMBER_LARGE_DB>>>; size="2 KB" }
      { count=<<<WF_SECTOR_NUMBER_SMALL_DB>>>; size="128" }
      { count=1; size="<<<GAP_WF_LOWER_BANK_END_TO_UPPER_BANK_START_KB>>> KB"; valid=false }
      { count=<<<WF_SECTOR_NUMBER_LARGE_DB>>>; size="2 KB" }
      { count=<<<WF_SECTOR_NUMBER_SMALL_DB>>>; size="128" }
    }
  }
"""

# TVII flash constants
CODEFLASH_BASE              = 0x10000000
CODEFLASH_LOWER_BANK_BASE   = CODEFLASH_BASE
CODEFLASH_UPPER_BANK_BASE   = 0x12000000
WORKFLASH_BASE              = 0x14000000
WORKFLASH_LOWER_BANK_BASE   = WORKFLASH_BASE
WORKFLASH_UPPER_BANK_BASE   = 0x15000000
SFLASH_BASE                 = 0x17000000
CODEFLASH_SECTOR_SIZE_LARGE = 32 * 1024
CODEFLASH_SECTOR_SIZE_SMALL =  8 * 1024
WORKFLASH_SECTOR_SIZE_LARGE =  2 * 1024
WORKFLASH_SECTOR_SIZE_SMALL = 128


def print_debug(message):
    """Print message if enabled, add a prefix string to indicate that it is a debug message."""
    if PRINT_DEBUG_MESSAGES is True:
        print("DEBUG> " + message)
    
def get_gap_cf_end_to_sflash_start(secnum_large, secnum_small):
    """Calculate the gap in KB from the end of CodeFlash (in single bank mode) to the start of the SFLASH."""
    cf_end = CODEFLASH_BASE + (CODEFLASH_SECTOR_SIZE_LARGE * secnum_large) + (CODEFLASH_SECTOR_SIZE_SMALL * secnum_small)
    gap_in_kb = (SFLASH_BASE - cf_end) // 1024
    print_debug("CODEFLASH_END:                                              {0:#010x}".format(cf_end))
    print_debug("CODEFLASH_END to SFLASH_START Gap:                          {0:#010x}".format(gap_in_kb * 1024))
    return gap_in_kb
    
def get_gap_cf_lower_bank_end_to_upper_bank_start(secnum_large, secnum_small):
    """Calculate the gap in KB from the end of the lower CodeFlash bank (in dual bank mode) to the start of the upper CodeFlash bank."""
    cf_lower_bank_end = CODEFLASH_LOWER_BANK_BASE + (CODEFLASH_SECTOR_SIZE_LARGE * secnum_large // 2) + (CODEFLASH_SECTOR_SIZE_SMALL * secnum_small // 2)
    gap_in_kb = (CODEFLASH_UPPER_BANK_BASE - cf_lower_bank_end) // 1024
    print_debug("CODEFLASH_LOWER_BANK_END:                                   {0:#010x}".format(cf_lower_bank_end))
    print_debug("CODEFLASH_LOWER_BANK_END to CODEFLASH_UPPER_BANK_START Gap: {0:#010x}".format(gap_in_kb * 1024))
    return gap_in_kb
    
def get_gap_cf_upper_bank_end_to_sflash_start(secnum_large, secnum_small):
    """Calculate the gap in KB from the end of the upper CodeFlash bank (in dual bank mode) to the start of the SFLASH."""
    cf_upper_bank_end = CODEFLASH_UPPER_BANK_BASE + (CODEFLASH_SECTOR_SIZE_LARGE * secnum_large // 2) + (CODEFLASH_SECTOR_SIZE_SMALL * secnum_small // 2)
    gap_in_kb = (SFLASH_BASE - cf_upper_bank_end) // 1024
    print_debug("CODEFLASH_UPPER_BANK_END:                                   {0:#010x}".format(cf_upper_bank_end))
    print_debug("CODEFLASH_UPPER_BANK_END to SFLASH_START Gap:               {0:#010x}".format(gap_in_kb * 1024))
    return gap_in_kb

def get_gap_wf_lower_bank_end_to_upper_bank_start(secnum_large, secnum_small):
    """Calculate the gap in KB from the end of the lower WorkFlash bank (in dual bank mode) to the start of the upper WorkFlash bank."""
    wf_lower_bank_end = WORKFLASH_LOWER_BANK_BASE + (WORKFLASH_SECTOR_SIZE_LARGE * secnum_large // 2) + (WORKFLASH_SECTOR_SIZE_SMALL * secnum_small // 2)
    gap_in_kb = (WORKFLASH_UPPER_BANK_BASE - wf_lower_bank_end) // 1024
    print_debug("WORKFLASH_LOWER_BANK_END:                                   {0:#010x}".format(wf_lower_bank_end))
    print_debug("WORKFLASH_LOWER_BANK_END to WORKFLASH_UPPER_BANK_START Gap: {0:#010x}".format(gap_in_kb * 1024))
    return gap_in_kb

def add_traveo_ii_entries(odb_file):
    """Generate the proper chip definitions for all the entries in the CSV file and add it to the ODB file."""
    with open(TVII_CHIP_LIST_CSV_FILE_WITH_REL_PATH, "r", newline='') as chip_list_file:
        # Define dict keys for the CSV columns and create DictReader object
        keys = ['desc', 'family_id', 'silicon_id', 'cf_secnum_large', 'cf_secnum_small', 'wf_secnum_large', 'wf_secnum_small']        
        chip_list_reader = csv.DictReader(chip_list_file, fieldnames=keys)
        
        # Go through each line of the CSV file
        for row in chip_list_reader:
            # Should not happen for DictReader
            if not row:
                continue
            # CSV file comment, just skip
            elif row['desc'].lstrip().startswith("//") is True:
                continue
            # Comment line for the ODB file, so just write it to the ODB file, prefixed with the proper comment character
            elif row['desc'].lstrip().startswith("#") is True:
                odb_file.write(row['desc'] + "\n")
                continue
            # Generate an empty line in the ODB
            elif row['desc'].lstrip().startswith("@") is True:
                odb_file.write("\n")
                continue
            
            # Output the currently processed entry on the console
            print(100 * "=")
            print("Processing: " + row['desc'])            
            
            # Calculate entry dependent flash related parameters
            cf_secnum_large = int(row['cf_secnum_large'].strip(), 0)
            cf_secnum_small = int(row['cf_secnum_small'].strip(), 0)
            wf_secnum_large = int(row['wf_secnum_large'].strip(), 0)
            wf_secnum_small = int(row['wf_secnum_small'].strip(), 0)            
            gap_cf_end_to_sflash_start                = get_gap_cf_end_to_sflash_start               (cf_secnum_large, cf_secnum_small)
            gap_cf_lower_bank_end_to_upper_bank_start = get_gap_cf_lower_bank_end_to_upper_bank_start(cf_secnum_large, cf_secnum_small)
            gap_cf_upper_bank_end_to_sflash_start     = get_gap_cf_upper_bank_end_to_sflash_start    (cf_secnum_large, cf_secnum_small)
            gap_wf_lower_bank_end_to_upper_bank_start = get_gap_wf_lower_bank_end_to_upper_bank_start(wf_secnum_large, wf_secnum_small)
            
            # Update the template string with entry specific data
            CURRENT_ENTRY = ENTRY_TEMPLATE
            CURRENT_ENTRY = CURRENT_ENTRY.replace("<<<DESCRIPTION>>>",                                  row['desc'])
            CURRENT_ENTRY = CURRENT_ENTRY.replace("<<<FAMILY_ID>>>",                                    row['family_id'].strip())
            CURRENT_ENTRY = CURRENT_ENTRY.replace("<<<SILICON_ID>>>",                                   row['silicon_id'].strip())
            CURRENT_ENTRY = CURRENT_ENTRY.replace("<<<CF_SECTOR_NUMBER_LARGE>>>",                       str(cf_secnum_large     ))
            CURRENT_ENTRY = CURRENT_ENTRY.replace("<<<CF_SECTOR_NUMBER_SMALL>>>",                       str(cf_secnum_small     ))
            CURRENT_ENTRY = CURRENT_ENTRY.replace("<<<CF_SECTOR_NUMBER_LARGE_DB>>>",                    str(cf_secnum_large // 2))
            CURRENT_ENTRY = CURRENT_ENTRY.replace("<<<CF_SECTOR_NUMBER_SMALL_DB>>>",                    str(cf_secnum_small // 2))
            CURRENT_ENTRY = CURRENT_ENTRY.replace("<<<WF_SECTOR_NUMBER_LARGE>>>",                       str(wf_secnum_large     ))
            CURRENT_ENTRY = CURRENT_ENTRY.replace("<<<WF_SECTOR_NUMBER_SMALL>>>",                       str(wf_secnum_small     ))
            CURRENT_ENTRY = CURRENT_ENTRY.replace("<<<WF_SECTOR_NUMBER_LARGE_DB>>>",                    str(wf_secnum_large // 2))
            CURRENT_ENTRY = CURRENT_ENTRY.replace("<<<WF_SECTOR_NUMBER_SMALL_DB>>>",                    str(wf_secnum_small // 2))
            CURRENT_ENTRY = CURRENT_ENTRY.replace("<<<GAP_CF_END_TO_SFLASH_START_KB>>>",                str(gap_cf_end_to_sflash_start)               )
            CURRENT_ENTRY = CURRENT_ENTRY.replace("<<<GAP_CF_LOWER_BANK_END_TO_UPPER_BANK_START_KB>>>", str(gap_cf_lower_bank_end_to_upper_bank_start))
            CURRENT_ENTRY = CURRENT_ENTRY.replace("<<<GAP_CF_END_DB_TO_SFLASH_START_KB>>>",             str(gap_cf_upper_bank_end_to_sflash_start)    )
            CURRENT_ENTRY = CURRENT_ENTRY.replace("<<<GAP_WF_LOWER_BANK_END_TO_UPPER_BANK_START_KB>>>", str(gap_wf_lower_bank_end_to_upper_bank_start))

            # Write entry to ODB file and add visual separator
            odb_file.write(CURRENT_ENTRY + "\n")
            odb_file.write("#" + ODB_FILE_ENTRY_SEPARATOR + "\n\n")


print("\nGenerating GreenHills ODB file, based on template file and CSV file with chip definitions:\n")

# Open template file and output file
with     open(ODB_TEMPLATE_FILE_WITH_REL_PATH, "r") as template_file:
    with open(ODB_OUTPUT_FILE_WITH_REL_PATH,   "w") as odb_file:
        
        # Go through each line of the template file and search for the insertion marker
        for line in template_file:
            # Just copy the line from the template to the output if it is not the insertion marker line
            if line.find(ODB_FILE_TEMPLATE_INSERTION_MARKER) == -1:
                odb_file.write(line)
            # Insertion marker line found. Replace it with the generated entries from the CSV file
            else:
                odb_file.write(120 * "#" + "\n")
                odb_file.write("# Traveo II entries generated by Cypress ODB file generator script on " + datetime.now().ctime() + "\n")
                odb_file.write(120 * "#" + "\n\n")
                
                add_traveo_ii_entries(odb_file)
                
                odb_file.write(120 * "#" + "\n")
                odb_file.write("# End of generated content.\n")
                odb_file.write(120 * "#" + "\n\n")
    
print("\n\nDone.")


