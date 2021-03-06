#' Extended Kalman Particle Filtering
#'
#' Function \code{ekpf_filter} performs a extended Kalman particle filtering with stratification
#' resampling, based on Van Der Merwe et al (2001).
#'
#' @param object of class \code{nlg_ssm}.
#' @param nsim Number of samples.
#' @param seed Seed for RNG.
#' @param ... Ignored.
#' @return A list containing samples, filtered estimates and the corresponding covariances,
#' weights from the last time point, and an estimate of log-likelihood.
#' @references Van Der Merwe, R., Doucet, A., De Freitas, N., & Wan, E. A. (2001). The unscented particle filter. In Advances in neural information processing systems (pp. 584-590).
#' @export
#' @rdname ekpf_filter
ekpf_filter <- function(object, nsim, ...) {
  UseMethod("ekpf_filter", object)
}
#' @method ekpf_filter nlg_ssm
#' @export
#' @rdname ekpf_filter
ekpf_filter.nlg_ssm <- function(object, nsim, seed = sample(.Machine$integer.max, size = 1), ...) {
  
  out <- ekpf(t(object$y), object$Z, object$H, object$T, 
    object$R, object$Z_gn, object$T_gn, object$a1, object$P1, 
    object$theta, object$log_prior_pdf, object$known_params, 
    object$known_tv_params, object$n_states, object$n_etas, 
    as.integer(object$time_varying), nsim, 
    seed)
  colnames(out$at) <- colnames(out$att) <- colnames(out$Pt) <-
    colnames(out$Ptt) <- rownames(out$Pt) <- rownames(out$Ptt) <- 
    rownames(out$alpha) <- object$state_names
  out$at <- ts(out$at, start = start(object$y), frequency = frequency(object$y))
  out$att <- ts(out$att, start = start(object$y), frequency = frequency(object$y))
  out$alpha <- aperm(out$alpha, c(2, 1, 3))
  out
}