/*
 * @turlapatykaushik
 * github url : github.com/turlapatykaushik

 * project description : We all know dice game and this project aims at finding
   the outputs of a dice rolled and the constraints are given by the user
*/

import random
def dice_stimulator(number_of_rolls,dice_size):
  for i in range(0,number_of_rolls):
    output = random.randint(1,dice_size)
    print "Die %d is rolled and the output is %d" %(i+1,output)
dice_stimulator(2,6)
