<!-- sieve of eratosthenes theorem -->

- sieve algo :

  - used for getting prime number form 1 to given number n <= 10^9

- segmented sieve:
  - after that we need to use segmented sieve n<= 10^12 also provide L,R
  - but condition: R-L < 10^6  
    e.g. l = 10^10 and R = 10^10 + 10^6 possible
    e.g. l = 10^10 and R = 10^12 not possible

<!-- concept -->

- global scope array size maximum:
  int n <= 10^7
  bool n <= 10^8

- main scope arrat size maximum:
  int n <= 10^6
  bool n <= 10^7

<!-- segemented sieve logic and algo -->

# steps:

- generate all prime till sqrt(r); : used sieve array and get all primes time sqrt(r)
- create an array from (r-l+1) and mark as 1
- For all prime mark its multiple as false
- Print all the primes from l to r in the (r-l+1) array.

<!-- need to read -->

1. Pigeon hole principle
2. catalan number
3. Inclution-exclution principle

Ques: factorial of an number 212! using %m --> 10^9+7
