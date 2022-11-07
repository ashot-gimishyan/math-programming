class Calculator(object):

    def read(self):
        """Read input from stdin"""
        return input()

    def eval(self, string):
        opers = ['+', '-' , '*', '/']
        nums = ['0','1','2','3','4','5','6','7','8','9']

        operators_list = []
        numbers_list = []

        string = string.split(' ')
        for token in string:
            if token in opers:
                operators_list.append(token)
            else:
                numbers_list.append(token)

        for num in numbers_list:
            for i in range(len(num)-1):
                if num[i] != '-' and num[i] != '.' and num[i] not in nums:
                    print(num)
                    print("Wrong operator")
                    return None

        count = 0
        # сначала вычислим * и / по приоритету операции
        for o in range(len(operators_list)):
            if operators_list[o] == '/':
                x = numbers_list.pop(o-count)
                y = numbers_list.pop(o-count)
                count += 1
                x = float(x)
                y = float(y)
                if y == 0:
                    print("Division by zero")
                    return None
                numbers_list.insert(o-count+1, x/y)

            if operators_list[o] == '*':
                x = numbers_list.pop(o-count)
                y = numbers_list.pop(o-count)
                count += 1
                numbers_list.insert(o-count+1  , float(x) * float(y))

        #print(numbers_list)
        for o in range(len(operators_list)):
            if operators_list[o] == '+':
                x = numbers_list.pop(0)
                y = numbers_list.pop(0)
                numbers_list.insert(0, float(x) + float(y))

            if operators_list[o] == '-':
                x = numbers_list.pop(0)
                y = numbers_list.pop(0)
                numbers_list.insert(0,  float(x) - float(y))

        return numbers_list[0]


    def loop(self):
        line = self.read()
        while line != "quit":
            value = self.eval(line)
            print(value)
            # Read next line of input
            line = self.read()

if __name__ == '__main__':
    calc = Calculator()
    calc.loop()
    
    
    
    
# 10 - 5 * 2 + 45 / 9 = 5
