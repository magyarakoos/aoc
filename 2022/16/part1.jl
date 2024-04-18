f = map(l -> match(r".{5}(..).{14}(\d+).{25}(.*)", l), readlines("input"))
println(f)
