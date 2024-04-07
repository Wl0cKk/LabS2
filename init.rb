BDIR = './base'
Dir.exist?(BDIR) ? exit(0) : Dir.mkdir(BDIR)
(1..15).each { |var|
    init_file = ->(fn) { File.new(fn, 'w+') }
    var_dir = "#{BDIR}/var#{var}" 
    Dir.mkdir(var_dir)
    Dir.mkdir("#{var_dir}/bin")
    init_file.("#{var_dir}/lab1-lvl2.c")
    init_file.("#{var_dir}/lab2-lvl1.c")
    (3..6).each { |i| init_file.("#{var_dir}/lab#{i}.c") }
}