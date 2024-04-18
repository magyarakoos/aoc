f = map(l -> match(r".{6}(.[A-Z]).{15}(\d+).{25}(.*)", l), readlines("input"))
println(f)
