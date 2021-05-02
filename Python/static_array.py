class StaticArray:
  """
  attributes:
    data_type: data type of the static array
    lenght: lenght of the array, initially zero 
    max: max length of the array
    data: effectivate storage of the data
  
  methods:
    get_value_at(): return the item at a given index
      ex: array[10, 20, 30]
      var = arr.get_value_at(0)
      now var equals 10
    push(): push a new item at the end of the array
    pop(): delete last item of the array
    view_array(): print all the items of the array beginning from 0
    view_complete_array(): same as 'view_array()', but prints even      void indexes of the array, useful for debug
    reverse_array(): reverse a given array and returns a copy of it
  """
  def __init__(self, data_type, max):
    # it will be by default an array of integers
    self.data_type = data_type
    # lenght of the array
    self.length: int = 0
    # max size of the array
    self.max = max
    # store the values
    self.data = [None] * max

  def get_value_at(self, index):
    return self.data[index] # O(1)

  def push(self, item):
    ret_length: int # cointains the updated length of the array to return,
                    # used to not make the code spaghetti like
    if (type(item) != self.data_type):
      ret_length = self.length
    elif (self.length + 1 <= self.max):
      self.data[self.length] = item
      self.length += 1
      ret_length = self.length
    else:
      print('sorry, index out of range')
      ret_length = self.length
    return ret_length # O(1)

  def pop(self):
    last_item: self.data_type = self.data[self.length - 1]
    self.length -= 1 
    # in a dynamic array we would delete the item
    # instead of setting it to none
    self.data[self.length] = None
    return last_item # O(1)

  def view_array(self):
    i: int = 0
    for i in range(self.length):
      print(f'{i}: ', self.data[i])
    return self.length # O(n)

  def view_complete_array(self):
    i: int = 0
    for i in range(self.max):
      print(f'{i}: ', self.data[i])
    return self.length # O(n)

  # delete an item of the array
  def delete(self, item):
    # finding the item index
    item_index: int = 0
    for i in range(self.length):
      if self.data[i] == item:
        #print(f'{arr.data[i]} is at index of {i}')
        item_index = i

    # changing the array
    for i in range(item_index, self.length - 1):
      self.data[i] = self.data[i + 1]

    self.data[self.length - 1] = None
    self.length -= 1

    return self.length # O(n)

  def reverse_array (self, given_array):
    ret_arr = StaticArray(given_array.data_type, given_array.length)

    i: int = 0
    for i in range(given_array.length -1, -1, -1):
      ret_arr.push(given_array.data[i])

    return ret_arr

  def merge_two_arrays(self, array_1, array_2):
    size_ret_arr = array_1.length + array_2.length
    dtype_ret_arr = array_1.data_type
    ret_arr = StaticArray(dtype_ret_arr, size_ret_arr)
    
    i:int = 0
    for i in range(array_1.length):
      ret_arr.push(array_1.data[i])

    for i in range(array_2.length):
      ret_arr.push(array_2.data[i])
    """
    we could merge more then two array taking as argument
    an array of arrays, but we should do:
    for i in range(size_array_of_array):
      for j in range(arr[i].lenght):
        ret_arr.push(arr[i].data[j])
    which is O(n^2)
    """

    """
    we could sort the arrays while merging, but that method is too
    complicated and not efficient, I think is better sort them all together for then sort the merged array.
    The section about sorting algos is at the end of the course,
    so not using the pre-buil python method is a TO DO
    """
    # ret_arr.data.sort()
    return ret_arr

# creating static array of 5 spaces
arr = StaticArray(int, 5)
arr.push(11)
arr.push(99)
arr.push(33)
arr.push(44)
arr.push(55)

arr2 = StaticArray(int, 2)
arr2.push(66)
arr2.push(77)

merged_arr = arr.merge_two_arrays(arr, arr2)

merged_arr.view_array()






