d = Dict('('=>')', '['=>']', '{'=>'}', '<'=>'>')
for l in readlines("input")
    s = Stack{Char}()    
    for c in l
        if c ∈ keys(d) push!(s, c) end
        if c != d[first(s)]
