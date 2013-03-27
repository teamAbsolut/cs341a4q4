desc "Run tests on the slow version"
task :testslow do
  puts "Testing"
  Dir.glob('tests/*') do |file|
    fileName = file[/[^\/]*$/]
    solution = File.open( File.join('solutions', fileName ) ).read.split(' ')
    output = `a4slow.exe <#{file}`.chomp

    if solution.include? output
      puts "Passed #{fileName}"
    else
      puts "Failed #{fileName}"
      puts "  Output: #{output}"
    end
  end
end

desc "Run tests on the fast version"
task :testfast do
  puts "Testing"
  Dir.glob('tests/*') do |file|
    next if File.directory?( file )
    fileName = file[/[^\/]*$/]
    solution = File.open( File.join('solutions', fileName ) ).read.split(' ')
    output = `a4fast <#{file}`.chomp

    if solution.include? output
      puts "Passed #{fileName}"
    else
      puts "Failed #{fileName}"
      puts "  Output: #{output}"
    end
  end
end

desc "Run a specific test"
task :specific, :arg1 do |t,args|
  solution = File.open( File.join('solutions', args[:arg1] ) ).read
  output = `a4slow <#{File.join('tests', args[:arg1] ) }`
  if solution == output
    puts "Passed #{args[:arg1]}"
  else
    puts "Failed #{args[:arg1]}"
    puts "  Output: #{output}"
  end
end

desc "Compiles the slow program"
task :compileslow do
  puts "Compiling"
  `g++ -o a4slow a4slow.cpp`
end

desc "Compiles the fast program"
task :compilefast do
  puts "Compiling"
  `g++ -o a4fast a4fast.cpp`
end

desc "Compiles a debug version"
task :compiledebug do
  puts "Compiling debug version"
  `g++ -o a4fast a4fast.cpp -DDEBUG`
end

task :default => :testslow
