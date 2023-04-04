#Node 
class Node:
  def __init__(self, data, next=None): #data 만 입력시 next 초기값 은 None이다.
    self.data = data 
#다음 데이터 주소 초기값 = None
  self.next = next ### 들여쓰기 하기
# class Node:
#   def __init__(self, data, next = None):
#     self.data = data
#     self.next = next
#Node 생성해보기(data = 1) 
node1 = Node(1)
#Node의 값과 포인터 출력하기
print(node1.data) 
print(node1.next)