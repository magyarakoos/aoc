f = map(s->split(s, "\n"), split(open(io->read(io, String), "input"),"\n\n"))
println(f)