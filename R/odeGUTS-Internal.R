# Workaround to get rid of "No visible binding for global variable" notes
# in package check. This notes are caused by uses of dplyr and tidyr.
if(getRversion() >= "2.15.1")  utils::globalVariables(c(
  ".", "Nsurv", "Nsurv_q50_check", "ppc_matching_valid", "SE_id",
  "Nsurv_q50_valid", "Nsurv_qinf95_valid", "Nsurv_qsup95_valid", "conc", "q50",
  "qinf95", "qsup95", "time"))
