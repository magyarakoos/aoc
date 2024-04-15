using DataStructures
d = Dict('('=>')', '['=>']', '{'=>'}', '<'=>'>')
v = Dict(')'=>3, ']'=>57, '}'=>1197, '>'=>25137)
p1 = 0
for l in readlines("input")
    s = Stack{Char}()    
    for c in l
        if c ∈ keys(d) push!(s, c)
        elseif c != d[first(s)] global p1 += v[c]; break
        else pop!(s) end
    end
    if !
end
println(p1)
