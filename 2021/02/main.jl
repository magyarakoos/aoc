f = map(l -> (split(l)[1][1], parse(Int, split(l)[2])), readlines("input"))
println(
    sum(map(x -> x[2], filter(t -> t[1] == 'f', f))) * 
    sum(map(x -> x[1] == 'd' ? x[2] : -x[2], filter(t -> t[1] != 'f', f)))
)
hpos = 0; depth = 0; aim = 0
for (t, x) in f
    if t == 'd' global aim += x
    elseif t == 'u' global aim -= x
    else
        global hpos += x
        global depth += aim * x
    end
end
println(hpos * depth)