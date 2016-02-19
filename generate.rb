#!/usr/bin/ruby

require 'FileUtils'

SOURCE_DIR="TemplatePlugin/**"
TEXT_FORMATS = [".cpp", ".h", ".pch", ".uplugin", ".cs"]

def path_replace(path, new_name)
  return path.gsub("TemplatePlugin", new_name)
end

def contents_replace(contents, old_name, new_name)
  return contents.gsub(old_name, new_name)
end

def get_all_files()
  return Dir.glob(File.join(SOURCE_DIR, "*"))
end

def create_project_files()
  get_all_files().each { | file |
    if File.file?(file) then
      new_path = path_replace(file, ARGV[0])
      #puts "#{file} -> #{new_path}"

      FileUtils.mkdir_p File.dirname(new_path)
      contents = File.open(file).read

      if File.extname(file) == ".uplugin" then
        contents = contents_replace(contents, "DeveloperName", ARGV[1])
      end
      
      if TEXT_FORMATS.include? File.extname(file) then
        contents = contents_replace(contents, "TemplatePlugin", ARGV[0])
      end

      File.open(new_path, 'w') { |new_file|
        new_file.write(contents)
      }
    end
  }
end

if ARGV.length < 1 then
    puts "Usage: ./generate.rb <New Plugin Name> <Developer Name>"
    exit 0
end

puts "Creating plugin with name: #{ARGV[0]}"
create_project_files()
