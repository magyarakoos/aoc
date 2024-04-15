d = Dict('('=>')', '('=>')', '('=>')', '('=>')')
for l in readlines("input")
    s = Stack{Char}()    
    for c in l
        if c ∈ ['(','[','{','<'] push!(s, c) end
        if 
