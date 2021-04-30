class StaticArray:
  def __init__(self, max):
    # it will be by default an array of integers
    self.data_type = int
    # lenght of the array
    self.length: int = 0
    # max size of the array
    self.max = max
    # store the values
    self.data = [None] * max

  # get the value at a precise index
  def get_value_at(self, index):
    return self.data[index] # O(1)

  # add an item at the end of the array
  def push(self, item):
    self.data[self.length] = item
    self.length += 1
    return self.length # O(1)
    # TO DO: list assignment out of range, debug

  # delete last element of the array
  def pop(self):
    last_item: self.data_type = self.data[self.length - 1]
    self.length -= 1 
    # in a dynamic array we would delete the item
    # instead of setting it to none
    self.data[self.length] = None
    return last_item # O(1)

  # show all the elements of the array
  def view_array(self):
    i: int = 0
    for i in range(self.length):
      print(f'{i}: ', self.data[i])
    return # O(n)

  """ TO DO: write pseducode about it
  # delete an item of the array
  def delete(self, item):
    i: self.data_type = 0
    # loop through the array
    for i in range(self.length):
      # found the item
      if self.data[i] == item:
        print('element found at index ', self.get_value_at(i))
        location: int = i
    
    self.length -= 1

    return self.length
  """


# creating static array of 5 spaces
arr = StaticArray(5)
arr.push(1)
arr.push(3)

try:
  arr.get_value_at(5)
except:
  print('bug')