class Stack:
    def __init__(self, cap):
        self.value = None
        self.cap = cap
        self.array = list()
        self.len = 0

    def push(self, value):
        self.array.append(value)
        self.len = len(self.array)
        print("Value added: ", value)
        return True

    def pop(self):
        try:
            self.value = self.array[-1]
            self.array.pop()
            return self.value
        except Exception as e:
            print(e)
            return False

    def display(self):
        print(*self.array)
        return True


stc = Stack(5)
for i in range(5, 10):
    stc.push(i)
stc.display()
for i in range(stc.len - 2):
    val1 = stc.pop()
    val2 = stc.pop()
    if val1-1 == val2 or val2 is False:
        continue
    else:
        print("Discontinued: ", val1, val2)
        stc.display()
        exit(2)
print("Successful")
