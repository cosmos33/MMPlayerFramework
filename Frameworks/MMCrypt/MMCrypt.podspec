Pod::Spec.new do |s|
  s.name         = 'MMCrypt'
  s.version      = '1.0.0'
  s.summary      = 'MMCrypt frameworks.'
  s.homepage     = 'https://www.baidu.com'
  s.author       = {"bao.zhen" => "bao.zhen@immomo.com" }
  s.source       = { :git => 'https://git.wemomo.com/bao.zhen/MMFrameworks.git', :tag => 'MMFrameworks/'+s.version.to_s }
  s.platform     = :ios, '9.0'
  s.requires_arc = true
  s.license      = {
    :type => 'MIT',
    :file => 'LICENSE'
  }
  s.description  = "MMCrypt frameworks. such as aes rsa"
  s.static_framework = true

  s.framework   = 'Foundation'
  s.vendored_frameworks = 'Products/MMCrypt.framework'

end
