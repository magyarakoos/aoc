d = Dict('('=>')', '['=>']', '{'=>'}', '<'=>'>')
v = Dict(')'=>3, ']'=>57, '}'=>1197, '<'=>'>')
p1 = 0
for l in readlines("input")
    s = Stack{Char}()    
    for c in l
        if c ∈ keys(d) push!(s, c) end
        if c != d[first(s)] global p1 += 
