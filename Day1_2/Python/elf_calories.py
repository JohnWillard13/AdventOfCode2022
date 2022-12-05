from sys import argv

with open(argv[1],'r') as f:
        lines = f.readlines()

#Go through each elf's calorie count to determine hSum
def calcMax():

    tSum = 0

    #hSum stores the amount of calories the elf with the highest amount is carrying
    #The value will change so long as another elf is found carrying more calories than any of the previous ones in the input
    hSum = 0
    
    #Convert from string to int
    #If line is blank, convert to zero
    for line in lines:
        line = line.rstrip('\n')
        if not line:
            line = 0
        
        else:
            line = int(line)
        
        tSum += line

        # #Checks if current elf holds the most calories so far
        # if tSum > hSum:
        #     hsum = tSum

        
        #If line is end of current elf (whitespace line) reset tSum to zero for next elf
        if line == 0:
            if tSum > hSum:
                hSum = tSum
            
            tSum = 0

    #End of file hSum check
    if tSum > hSum:
        hSum = tSum

    return hSum

def main():
    maxSum = calcMax()
    print("The elf carrying the most calories is carrying " + str(maxSum) + " calories! Holy Christmas!")
    
if __name__ == '__main__':
    main()
