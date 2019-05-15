Pod::Spec.new do |s|

  s.name         = "openssl-lib"
  s.version      = "0.2.3"
  s.summary      = "openssl-lib."

  s.description  = "ffmpeg third-party openssl-lib."

  s.homepage     = "https://git.wemomo.com/base/openssl-lib.git"

  s.license      = { :type => 'MIT', :text => <<-EOS
Copyright 2012
Permission is granted to openssl
EOS
}
  s.author       = { "shuyj" => "shu.yajun@immomo.com" }
  s.platform     = :ios, "7.0"

  s.ios.deployment_target = "7.0"
  s.static_framework = true

  s.source       = { :git => "https://git.wemomo.com/base/openssl-lib.git", :tag => s.name+'/'+s.version.to_s }

  s.source_files = "openssl/include/**/*.{h}"

  s.header_mappings_dir = 'openssl/include'
  s.vendored_libraries = 'openssl/lib/*.a'

  # s.vendored_frameworks = 'openssl/openssl.framework'

end
