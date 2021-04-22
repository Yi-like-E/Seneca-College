/*
Question 1 Part A (7 Marks):
Seneca Newnham room numbers are numbered with the Building Name (i.e., a letter, one of A, B, C, D, E, F, G, H, I, or K), 
followed by a 4-digit number. For example, “A1034.” In addition, a few rooms also have an optional final letter, for example: “B2051A”.
Write a function isValidRoom that takes a string and returns true if it is formatted as a valid room number, and false otherwise. 
Calling isValidRoom(“A103”) or isValidRoom(“1043A”) should return false. Calling isValidRoom(“A1034”) or isValidRoom(“A1034B”) or 
isValidRoom(“K4444”) should return true.
*/
function isValidRoom(name) {
  let flag = true;
  if (name.match(/[A-IK]\d{4}[A-Z]?/)) {
    // Since the question didn't specify that the optional final letter will have a range like the starting letter, 
    //the range is set to A to Z.
    flag;
  } else {
    flag = false;
  }

  return flag;
}

/*
Question 2 (6 Marks)
Write a function fixup(sentences, problem, fix). The function takes two arguments: sentence – a string of text; problem – a string, 
a word to be replaced; fix – a string, a new word to use. The fixup function returns an Array of Strings.
Your function allows a problem word in an Array of sentences to be corrected. 
For example, you could replace the word ‘color’ with ‘colour’ in all of the sentences: fixup(sentences, ‘color’, colour’)
*/
function fixup(sentences, problem, fix) {
  let split, i;

  split = sentences.split(" ");

  for (i = 0; i < split.length; i++) {
    if (split[i].match(problem)) {
      split[i] = fix;
    }
  }

  return split;
}

/*
Question 3 (3 Marks)
Write a function, useDelimiter, which takes an Array and a String as arguments, and returns a String with the Array elements delimited 
by the string argument.
Calling useDelimiter ( [1, 2, 3], “:” ) should return “1:2:3” and useDelimiter ( [1, 2, 3], “...” ) should return “1...2...3”.
*/
function useDelimiter(arg, ele) {
  return arg.join(ele);
}

/*
Question 4 (7 Marks)
Rewrite this function twice, once using forEach() and then again using map(). Which of the 3 styles is your favourite 
and why do you like it best? What advantage(s) does it have over the other methods?

function square(numbers) {
  let squares = [];
  for (let i = 0; i < numbers.length; i++) {
    let number = numbers[i];
    squares.push(number * number);
  }
  return squares;
}
*/

function square(numbers) {
  let squares = [];
  numbers.forEach((element) => {
    squares.push(element * element);
  });
  return squares;
}

function square(numbers) {
  let squares = numbers.map((num) => num * num);
  return squares;
}

/* 
I prefer the forEach() since it is like a simplified version of the for loop, but without the need to specify the
condition inside the for loop as forEach() executes a provided function once for each array element. 
map() on the other hand, creates a new array consists with the results of calling a provided function on every element 
in the calling array.
As someone who is learning c and c++ now, forEach() has the advantage of having a structure similar to the for loop and 
it's easier to understand. map() is very efficient, but since it returns a new array, it may needs conversion to the 
desired type based on the goal of the written function.
*/
