/*
 * @turlapatykaushik
 * github url : github.com/turlapatykaushik

 * project description : The CPU selects a number at random and the player has
   to find the number within 5 guesses. If guessed, player wins else loses
*/

import random

total_guesses = 0
number_selected = random.randint(1,10)
print "I selected a number between 1 and 50, Can you guess it in 5 chances"
while(total_guesses < 5):
  total_guesses = total_guesses + 1
  print "guess it"
  guess = input()
  guess = int(guess)
  if(guess < number_selected):
    print "your number is lesser than what I selected"
  elif(guess > number_selected):
    print "your number is greater than what I selected"
  elif(guess == number_selected):
    break
if(guess == number_selected):
  print "you guessed it in %d chances" % (total_guesses)
else:
  print "sorry, you lost"
