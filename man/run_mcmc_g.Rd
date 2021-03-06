% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/run_mcmc.R
\name{run_mcmc.gssm}
\alias{run_mcmc.gssm}
\alias{run_mcmc.bsm}
\alias{run_mcmc.ar1}
\alias{run_mcmc.lgg_ssm}
\title{Bayesian Inference of Linear-Gaussian State Space Models}
\usage{
\method{run_mcmc}{gssm}(object, n_iter, type = "full",
  n_burnin = floor(n_iter/2), n_thin = 1, gamma = 2/3,
  target_acceptance = 0.234, S, end_adaptive_phase = TRUE,
  n_threads = 1, seed = sample(.Machine$integer.max, size = 1), ...)

\method{run_mcmc}{bsm}(object, n_iter, type = "full",
  n_burnin = floor(n_iter/2), n_thin = 1, gamma = 2/3,
  target_acceptance = 0.234, S, end_adaptive_phase = TRUE,
  n_threads = 1, seed = sample(.Machine$integer.max, size = 1), ...)

\method{run_mcmc}{ar1}(object, n_iter, type = "full",
  n_burnin = floor(n_iter/2), n_thin = 1, gamma = 2/3,
  target_acceptance = 0.234, S, end_adaptive_phase = TRUE,
  n_threads = 1, seed = sample(.Machine$integer.max, size = 1), ...)

\method{run_mcmc}{lgg_ssm}(object, n_iter, type = "full",
  n_burnin = floor(n_iter/2), n_thin = 1, gamma = 2/3,
  target_acceptance = 0.234, S, end_adaptive_phase = TRUE,
  n_threads = 1, seed = sample(.Machine$integer.max, size = 1), ...)
}
\arguments{
\item{object}{Model object.}

\item{n_iter}{Number of MCMC iterations.}

\item{type}{Type of output. Default is \code{"full"}, which returns
samples from the posterior \eqn{p(\alpha, \theta)}. Option \code{"summary"} does not simulate
states directly but computes the posterior means and variances of states using
fast Kalman smoothing. This is slightly faster, memory  efficient and
more accurate than calculations based on simulation smoother. Using option \code{"theta"} will only
return samples from the marginal posterior of the hyperparameters \eqn{\theta}.}

\item{n_burnin}{Length of the burn-in period which is disregarded from the
results. Defaults to \code{n_iter / 2}. Note that all MCMC algorithms of \code{bssm}
 used adaptive MCMC during the burn-in period in order to find good proposal.}

\item{n_thin}{Thinning rate. All MCMC algoritms in \code{bssm} use the jump chain
representation, and the thinning is applied to these blocks.
Defaults to 1.}

\item{gamma}{Tuning parameter for the adaptation of RAM algorithm. Must be
between 0 and 1 (not checked).}

\item{target_acceptance}{Target acceptance ratio for RAM. Defaults to 0.234.}

\item{S}{Initial value for the lower triangular matrix of RAM
algorithm, so that the covariance matrix of the Gaussian proposal
distribution is \eqn{SS'}. Note that for some parameters 
(currently the standard deviation and dispersion parameters of bsm models) the sampling
is done for transformed parameters with internal_theta = log(1 + theta).}

\item{end_adaptive_phase}{If \code{TRUE} (default), $S$ is held fixed after the burnin period.}

\item{n_threads}{Number of threads for state simulation.}

\item{seed}{Seed for the random number generator.}

\item{...}{Ignored.}
}
\description{
Bayesian Inference of Linear-Gaussian State Space Models
}
