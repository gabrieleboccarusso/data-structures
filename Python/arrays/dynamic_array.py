class dynamic_array:
  def __init__ (self, dtype, max = 1):
    self.max: int = max
    self.length: int = 0
    self.data: dtype = [None] * max

  def push (self, item):
    if (self.length + 1 <= self.max):
      self.data[self.length] = item
      self.length += 1
    else:
      self.double_spaces()
      self.push(item)

    return self.length

  def double_spaces(self):
    dummy_arr: dtype = [None] * self.max
    i: int = 0

    for i in range(self.length):
      dummy_arr[i] = self.data[i]

    self.max *= 2
    self.data: dtype = [None] * self.max

    for i in range(self.length):
      self.data[i] = dummy_arr[i]

  def view_array(self):
    i: int = 0
    print(f'length: {self.length}')
    for i in range(self.length):
      print(f'{i}: ', self.data[i])
    print(f'max: {self.max}')
    return self.length # O(n)
arr = dynamic_array(int)
arr.push(11)
arr.push(22)
arr.push(33)
arr.push(44)
arr.push(55)
arr.push(66)

arr.view_array()