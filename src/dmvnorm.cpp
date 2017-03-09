#include "bssm.h"

//[[Rcpp::export]]
double dmvnorm(const arma::vec& x, const arma::vec& mean,  
  const arma::mat& sigma, bool lwr, bool logd) { 
  
  double out = -arma::datum::inf;
  
  unsigned int p = x.n_elem;
  
  if (lwr) {
    arma::uvec nonzero = arma::find(sigma.diag() > (arma::datum::eps * p * sigma.diag().max()));
    arma::mat S = inv(trimatl(sigma(nonzero, nonzero)));
    arma::vec tmp = S * (x.rows(nonzero) - mean.rows(nonzero));
    out = -0.5 * (nonzero.n_elem * std::log(2.0 * M_PI) + 
      2.0 * sum(log(arma::diagvec(sigma.submat(nonzero, nonzero)))) + 
      arma::as_scalar(tmp.t() * tmp));
  } else {
    arma::mat U(p, p);
    arma::mat V(p, p);
    arma::vec s(p);
    bool success = arma::svd_econ(U, s, V, sigma, "left");
    
    if (success) {
      arma::uvec nonzero = arma::find(s > (arma::datum::eps * p * s(0)));
      arma::vec tmp = U.cols(nonzero).t() * (x - mean);
      out = -0.5 * (nonzero.n_elem * std::log(2.0 * M_PI) + sum(log(s(nonzero))) + 
        arma::as_scalar(tmp.t() * arma::diagmat(1.0 / s(nonzero)) * tmp));
    }
  }
  
  if (!logd) {
    out = exp(out);
  }
  
  return(out);
}

//[[Rcpp::export]]
double precompute_dmvnorm(const arma::mat& sigma, arma::mat& Linv, const arma::uvec& nonzero) { 
  
  unsigned int p = sigma.n_cols;
  Linv = arma::inv(arma::trimatl(sigma(nonzero, nonzero)));
  double constant = -0.5 * nonzero.n_elem * std::log(2.0 * M_PI) + 
    arma::sum(log(Linv.diag()));
  return constant;
}
//[[Rcpp::export]]
double fast_dmvnorm(const arma::vec& x, const arma::vec& mean, 
  const arma::mat& Linv, const arma::uvec& nonzero, const double constant) { 
  
  arma::vec tmp = Linv * (x.rows(nonzero) - mean.rows(nonzero));
  return constant - 0.5 * arma::accu(tmp % tmp);
}

