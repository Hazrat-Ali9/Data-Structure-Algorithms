class MyClass(object):
    def set_val(self, val):
        self.value = val

    def get_val(self):
        # print(self.value)
        return self.value


a = MyClass()
b = MyClass()

a.set_val(10)
b.set_val(100)

a.get_val()
b.get_val()

