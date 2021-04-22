/* Question 1
Question 1 Part A (5 Marks):
Write a function declaration called sumStrings that takes three String arguments: one, two, and three. 
Convert these values to Numbers, add them together, and return the result.
Calling sumStrings(“1”, “2”, “3”) should return the Number 6 */
function sumStrings(one, two, three) {
  var sum;
  sum = Number(one) + Number(two) + Number(three);
  return console.log(sum);
}

/* Question 1 Part B (1 Mark)
Convert your answer from Question 1 to a Function Expression. */
var sumStrings = function (one, two, three) {
  var sum;
  sum = Number(one) + Number(two) + Number(three);
  return console.log(sum);
};

/* Question 2 (6 Marks)
Simulate rolling a dice using Math.random(). Your roll function should allow the caller to specify any number 
of sides, but default to 6 if no side count is given: roll() assumes a 6 sided dice, returning a random number 
between 1 and 6, while roll(50) uses a 50 sided dice, and returns a random number between 1 and 50.
*/
function roll(numSides) {
  var defaultSides = 6;
  numSides = numSides || defaultSides;
  return console.log(Math.floor(Math.random() * (numSides - 1) + 1));
}

// roll();
// roll(50);

/* Question 3 (7 Marks)
Write a function, average, which accepts any number of Number arguments, calculates their average, and returns 
the result formatted as a String. Calling average(10, 20) should return “Average is 15”, and average(256, 8, 32, 128, 16, 1024) 
should return “Average is 244”. 
*/
function average(...num) {
  var sum = 0,
    i,
    avg;
  for (i = 0; i < num.length; i++) {
    sum += num[i];
  }
  avg = sum / num.length.toString();
  return console.log("Average is", avg);
}

/* Question 4 (4 Marks)
Explain the following code in your own words, discussing how it uses JavaScript scope and closures.
function createFn(factor) {
    return function(value) {
        return value * factor;
    };
}
let fn = createFn(10);
console.log(fn(6));  // What will this print and why?
*/

/* 
console.log(fn(6)) will return 60 because the line let fn = createFn(10); declare and assign the variable fn to calling the createFn with a 
number 10, which returns a function inside the createFn that takes in another number, 6, from fn(6).
Thus, the result returned is 10 * 6, which is 60.
// The function createFn takes in an argument, factor, and return to a function that takes in another argument, value. 
// The referenced function inside the createFn is used to return the result of multiplication between the argument from createFn, 
// and its argument. The result is what will be shown at the end of the execution of createFn.
The way this code is designed is having a nesting of scopes that follows the JavaScript's function scope rule so that the variable,
factor, can be shared from createFn function after it has closed over a scope, and it's then used in the fn function nesting within. 
 */
