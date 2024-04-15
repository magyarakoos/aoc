using DataStructures
d = Dict('('=>')', '['=>']', '{'=>'}', '<'=>'>')
v = Dict(')'=>3, ']'=>57, '}'=>1197, '>'=>25137)
println(d)
p1 = 0
for l in readlines("input")
    s = Stack{Char}()    
    for c in l
        if c ∈ keys(d) 
            push!(s, c)
        elseif c != d[first(s)] 
            global p1 += 1
            break
        else 
            push!(s, c)
        end
    end
end
println(p1)
