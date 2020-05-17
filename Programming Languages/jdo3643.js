// Author: Jerry Olds
// ID: 1001533643
// Date: 9/23/2018

// #1
var inputtable = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]; // Initialize array inputtable to values 1-10
console.log(inputtable); // Output numbers 1-10

// #2a
var fiveTable = inputtable.map(x => x * 5); // Multiply each element of inputtable by 5 to get multiples of 5 from 1-51 
console.log(fiveTable); // Output multiples of 5 from 1-51

// #2b
var thirteenTable = inputtable.map(x => x * 13); // Multiply each element of inputtable by 13 to get multiples of 13 from 1-131
console.log(thirteenTable); // Output multiples of 13 from 1-131

// #2c
var  squaresTable = inputtable.map(x => x * x); // Multiply inputtable by itself to get squares of inputtable
console.log(squaresTable); // Output squares of inputtable

// #3
var fiveTable2 = fiveTable.map(x => x + 50); // Add 50 to fiveTable to get multiples of 5 from 55-100
var oddMultiplesOfFive1 = fiveTable.filter(x => x % 2 == 1); // Get odd multiples of 5 from 5-50 
var oddMultiplesOfFive2 = fiveTable2.filter(x => x % 2 == 1); // Get odd multiples of 5 from 55-100
console.log(oddMultiplesOfFive1, oddMultiplesOfFive2); // Output odd multiples of 5 from 5-100

// #4
var sevenTable = inputtable.map(x => x * 7); // Multiply inputtable by 7 to get multiples of 7 from 7-70
var sevenTable2 = sevenTable.map(x => x + 70); // Add 70 to sevenTable to get multiples of 7 from 77-140
var evenMultiplesOfSeven1 = sevenTable.filter(x => x % 2 == 0); // Get even multiples of 7 from 7-70
var evenMultiplesOfSeven2 = sevenTable2.filter(x => x % 2 == 0 && x <= 100); // Get even multiples of 7 from 77-100
console.log(evenMultiplesOfSeven1, evenMultiplesOfSeven2); // Output even multiples of 7 from 7-100

// #5
var cylinder_volume = r => h => (r * r * h * 3.14); // Refactor original cylinder_volume function in to a curried function
var volume = cylinder_volume(5)(10); // Calculate volume of cylinder with radius 5 and height 10 using curried function
console.log(volume); // Output volume of cylinder with radius 5 and height 10

// #6
makeTag = function(beginTag, endTag){  // makeTag function from homework
    return function(textcontent){
        return beginTag + textcontent + endTag;
    }
}

var tags = makeTag("Weight: ", " lbs"); // Send beginTag and endTag to makeTag function and return to tags
var tableRow = tags("170"); // Send tags to function with textcontent and return to tableRow
console.log(tableRow); // Output tableRow