f = map(l -> (split(l)[1][1], parse(Int, split(l)[2])), readlines("input"))
println(
    sum(map(x -> x[2], filter(t -> t[1] == 'f', f))) * 
    map(x -> x, filter(t -> t[1] != 'f', f))
)
# input.Where(t => t.task != 'f').Select(t => t.task == 'd' ? t.x : -t.x).Sum());