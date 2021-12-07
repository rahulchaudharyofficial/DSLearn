class Test:
    def __init__(self, name) -> None:
        self.name = name


l = []
for i in range(1, 11):
    l.append(Test('RC'+str(i)))

print(l)