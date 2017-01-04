// #ifndef ISC_H
// #define ISC_H
// 
// #include <RcppArmadillo.h>
// 
// template <typename T>
// void is_correction(T model, const arma::mat& theta_store, const arma::mat& y_store, const arma::mat& H_store,
//   const arma::vec& ll_approx_u, const arma::uvec& counts, unsigned int nsim_states,
//   unsigned int n_threads, arma::vec& weights_store, arma::cube& alpha_store, 
//   bool const_m, const arma::uvec& seeds);
// 
// template <typename T>
// void is_correction_summary(T mod, const arma::mat& theta_store, const arma::mat& y_store, const arma::mat& H_store,
//   const arma::vec& ll_approx_u, const arma::uvec& counts, unsigned int nsim_states,
//   unsigned int n_threads, arma::vec& weights_store, 
//   arma::mat& alphahat, arma::cube& Vt, arma::mat& mu, arma::cube& Vmu, 
//   bool const_m, const arma::uvec& seeds);
// 
// 
// template <typename T>
// void is_correction_bsf(T model, const arma::mat& theta_store, const arma::vec& ll_store, 
//   const arma::uvec& counts, unsigned int nsim_states,
//   unsigned int n_threads, arma::vec& weights_store, arma::cube& alpha_store, 
//   bool const_m, const arma::uvec& seeds);
// template <typename T>
// void is_bsf_cm(T mod, const arma::mat& theta_store, const arma::vec& ll_store, 
//   const arma::uvec& counts, unsigned int nsim_states, arma::vec& weights_store, 
//   arma::cube& alpha_store);
// template <typename T>
// void is_bsf_ncm(T mod, const arma::mat& theta_store, const arma::vec& ll_store, 
//   const arma::uvec& counts, unsigned int nsim_states, arma::vec& weights_store, 
//   arma::cube& alpha_store);
// 
// template <typename T>
// void is_correction_bsf_summary(T mod, const arma::mat& theta_store, 
//   const arma::vec& ll_store, const arma::uvec& counts, unsigned int nsim_states,
//   unsigned int n_threads, arma::vec& weights_store, arma::mat& alphahat, arma::cube& Vt, 
//   arma::mat& mu, arma::cube& Vmu, bool const_m, const arma::uvec& seeds);
// 
// template <typename T>
// void is_correction_psif(T model, const arma::mat& theta_store, const arma::mat& y_store, const arma::mat& H_store,
//   const arma::mat& ll_approx_u, const arma::uvec& counts, unsigned int nsim_states,
//   unsigned int n_threads, arma::vec& weights_store, arma::cube& alpha_store, bool const_m, 
//   const arma::uvec& seeds);
// template <typename T>
// void is_psi_ncm(T mod, const arma::mat& theta_store, const arma::mat& y_store, const arma::mat& H_store,
//   const arma::mat& ll_approx_u, const arma::uvec& counts, unsigned int nsim_states,
//   arma::vec& weights_store, arma::cube& alpha_store);
//   template <typename T>
// void is_psi_ncm(T mod, const arma::mat& theta_store, const arma::mat& y_store, const arma::mat& H_store,
//   const arma::mat& ll_approx_u, const arma::uvec& counts, unsigned int nsim_states,
//   arma::vec& weights_store, arma::cube& alpha_store);
//     
// template <typename T>
// void is_correction_psif_summary(T mod, const arma::mat& theta_store, const arma::mat& y_store, const arma::mat& H_store,
//   const arma::mat& ll_approx_u, const arma::uvec& counts, unsigned int nsim_states,
//   unsigned int n_threads, arma::vec& weights_store, arma::mat& alphahat, arma::cube& Vt, 
//   arma::mat& mu, arma::cube& Vmu, bool const_m, const arma::uvec& seeds);
// 
// 
// #endif
