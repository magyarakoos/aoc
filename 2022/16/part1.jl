f = map(l -> match(r".{6}(..).{14}(\d+).{25}(.*)", l), readlines("input"))
println(f)
