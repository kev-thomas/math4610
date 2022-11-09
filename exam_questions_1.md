# Math 4610 Exam I Questions - Fall 2022

1. Define relative and absolute errors and give examples where relative error is a better measure and examples where absolute error may be a better measure of differences.
  - Absolute error is simply how large the error between the expected and actual measurements are, while relative error is how large the error is proportional to the actual value. Relative error is better in most cases, such as measuring the height of a person in inches, whereas absolute error can be suitable for scenarios where the exact difference matters, such as manufacturing a part that must be a certain length.

2. Describe the difference between the concepts of accuracy, efficiency, and robustness in the development of algorithms for the approximation of solutions of mathematical problems.
  - Accuracy is how close to the actual value the method of approximation can get.
  - Efficiency is how quickly we can obtain our answer/how much computing power is required to obtain it.
  - Robustness is how resilient/capable the algorithm is in dealing with various types of inputs or problems.
  - A good algorithm will have an emphasis on the most important aspect, while maintaining a certain level of quality in other aspects. It's possible to have a reasonably accurate algorithm that is extremely efficient, but may not be as robust as another that is more robust but less efficient (like comparing a small hybrid sedan to a 4WD truck).


3. Define the rounding unit (or the machine precision) and explain the importance of the rounding unit for computation.
  - Machine precision is important because it determines how accurate approximations made can be.

4. What is a nonlinear equation? Compare this to linear equations.
  - A nonlinear equation is one that does not form a straight line on a graph and cannot be expressed in the general form of $$y = mx + b$$

5. Is the bisection (i) efficient, (ii) accurate, (iii) robust? What smoothness conditions on the function are needed for Bisection to work?
  - The bisection method is not efficient and is not very accurate, but it is very robust. The function must be continous on the interval [a, b], and f(a) and f(b) must be opposing signs. If these conditions are not met, then the method may not converge to a root.

6. Does the bisection method provide a robust platform for the development of algorithms for the solution of systems of nonlinear equations?

7. What are basic conditions for fixed point iteration to converge when searching for the root of a nonlinear function of a single variable. How are these conditions related to the iteration function, $$g(x)$$, defined in terms of the original function, $$f$$, defined as the input of a root finding problem?

8. State two advantages and two disadvantages of Newton's method for finding roots of nonlinear functions.

9. Why would a person use the Secant method in place of Newton's method?

10. Distinguish between the terms data fitting, interpolation, and polynomial iteration.
  - Data fitting is the process of generating a function that has the best fit to a set of data points.
  - Interpolation is estimating new data points based on an existing set of data points.
  - Polynomial interpolation is using the lowest degree polynomial possible to perform interpolation.

11. State one advantage and two disadvantages of using the monomial basis for polynomial interpolation.

12. Define Lagrange polynomials (the cardinal functions) and how are they used in the development of algorithms for numerical integration.
  - Lagrange polynomials are the unique lowest degree polynomials used for interpolation. 

13. We have bumped into errors in the approximating roots of functions, approximating derivatives using difference quotients, approximations of solutions of differential equations and approximations of definite integrals.
    $$
      | error | \leq C\ h^p
    $$
    Write a brief explanation of the formula in terms the increment, $$h$$, the constant, $$C$$, and how to compute these parameters. Use an example like Newton's method for finding roots of functions.

14. Discuss the pros and cons of using the Trapezoid rule for approximating definite integrals.
  - The trapezoidal rule is decently accurate and simple, but not as accurate as other methods. If the function is concave up it will overestimate, and if it is concave down it will underestimate.

15. Compare the explicit and implicit Euler methods for approximate solution of initial value problems. You can use the logistic equation to illustrate your explanations.