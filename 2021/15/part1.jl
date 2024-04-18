using DataStructures
m = map(l -> split(l, ""), readlines("input"))
q = BinaryMinHeap{Int}()
