//
// Created by Peter on 4/11/2018.
//

#ifndef ASS2_BST_PROGRAM_CONCOLORS_H
#define ASS2_BST_PROGRAM_CONCOLORS_H



#include <string>

public class ConsolColor {
public:

    // Reset
  std::string RESET = "\033[0m";  // Text Reset

    // Regular Colors
  std::string blk = "\033[0;30m";   // blk
  std::string rd = "\033[0;31m";     // rd
  std::string grn = "\033[0;32m";   // grn
  std::string ylo = "\033[0;33m";  // ylo
  std::string blu = "\033[0;34m";    // blu
  std::string prpl = "\033[0;35m";  // prpl
  std::string cyan = "\033[0;36m";    // cyan
  std::string wht = "\033[0;37m";   // wht

    // Bold
  std::string blk_bld = "\033[1;30m";  // blk
  std::string rd_bld = "\033[1;31m";    // rd
  std::string grn_bld = "\033[1;32m";  // grn
  std::string ylo_bld = "\033[1;33m"; // ylo
  std::string blu_bld = "\033[1;34m";   // blu
  std::string prpl_bld = "\033[1;35m"; // prpl
  std::string cyan_bld = "\033[1;36m";   // cyan
  std::string wht_bld = "\033[1;37m";  // wht

    // Underline
  std::string blk_ul = "\033[4;30m";  // blk
  std::string rd_ul = "\033[4;31m";    // rd
  std::string grn_ul = "\033[4;32m";  // grn
  std::string ylo_ul = "\033[4;33m"; // ylo
  std::string blu_ul = "\033[4;34m";   // blu
  std::string prpl_ul = "\033[4;35m"; // prpl
  std::string cyan_ul = "\033[4;36m";   // cyan
  std::string wht_ul = "\033[4;37m";  // wht

    // Background
  std::string blk_bg = "\033[40m";  // blk
  std::string rd_bg = "\033[41m";    // rd
  std::string grn_bg = "\033[42m";  // grn
  std::string ylo_bg = "\033[43m"; // ylo
  std::string blu_bg = "\033[44m";   // blu
  std::string prpl_bg = "\033[45m"; // prpl
  std::string cyan_bg = "\033[46m";   // cyan
  std::string wht_bg = "\033[47m";  // wht

    // High Intensity
  std::string blk_brt = "\033[0;90m";  // blk
  std::string rd_brt = "\033[0;91m";    // rd
  std::string grn_brt = "\033[0;92m";  // grn
  std::string ylo_brt = "\033[0;93m"; // ylo
  std::string blu_brt = "\033[0;94m";   // blu
  std::string prpl_brt = "\033[0;95m"; // prpl
  std::string cyan_brt = "\033[0;96m";   // cyan
  std::string wht_brt = "\033[0;97m";  // wht

    // Bold High Intensity
  std::string blk_bld_brt = "\033[1;90m"; // blk
  std::string rd_bld_brt = "\033[1;91m";   // rd
  std::string grn_bld_brt = "\033[1;92m"; // grn
  std::string ylo_bld_brt = "\033[1;93m";// ylo
  std::string blu_bld_brt = "\033[1;94m";  // blu
  std::string prpl_bld_brt = "\033[1;95m";// prpl
  std::string cyan_bld_brt = "\033[1;96m";  // cyan
  std::string wht_bld_brt = "\033[1;97m"; // wht

    // High Intensity backgrounds
  std::string blk_bg_brt = "\033[0;100m";// blk
  std::string rd_bg_brt = "\033[0;101m";// rd
  std::string grn_bg_brt = "\033[0;102m";// grn
  std::string ylo_bg_brt = "\033[0;103m";// ylo
  std::string blu_bg_brt = "\033[0;104m";// blu
  std::string prpl_bg_brt = "\033[0;105m"; // prpl
  std::string cyan_bg_brt = "\033[0;106m";  // cyan
  std::string wht_bg_brt = "\033[0;107m";   // wht

}

#endif //ASS2_BST_PROGRAM_CONCOLORS_H
