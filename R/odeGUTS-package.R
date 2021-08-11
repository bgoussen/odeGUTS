#' @references
#'  Virgile Baudrot, Sandrine Charles, Marie Laure Delignette-Muller, Wandrille
#'  Duchemin, Benoit Goussen, Nils Kehrein, Guillaume, Kon-Kam-King,
#'  Christelle Lopes, Philippe Ruiz, Alexander Singer and Philippe Veber (2021).
#'  morse: Modelling Tools for Reproduction and Survival Data in Ecotoxicology.
#'  R package version 3.3.1. https://CRAN.R-project.org/package=morse
#' @keywords internal
"_PACKAGE"

# The following block is used by usethis to automatically manage
# roxygen namespace tags. Modify with care!
## usethis namespace: start
#' @useDynLib odeGUTS, .registration = TRUE
#' @importFrom stats lag quantile rbinom
## usethis namespace: end
NULL

#' Model calibration results for a GUTS-SD theoretical species exposed to a compound.
#'
#' @name fit_odeGUTS
#' @docType data
#' @usage data(fit_odeGUTS)
#' @format A list of class \code{survFit} constructed
#' \describe{
#' \item{\code{mcmc}}{A list of mcmc chain results}
#' \item{\code{model_type}}{A character string containing the type of GUTS model used (here 'SD').}
#' }
#' @keywords dataset
NULL
