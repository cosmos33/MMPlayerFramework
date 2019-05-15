Pod::Spec.new do |s|
  s.name             = 'MMMediaProxyOnly'
  s.version          = '0.5.7'
  s.summary          = 'Pod for MMMediaProxyOnly'
  s.description      = '整合播放器代理库，以pod的形式对外开放。如有问题请及时沟通谢谢～'
  s.homepage         = 'https://git.wemomo.com/base/ProxyPlayerPod.git'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Zou Guowei' => 'zou.guowei@immomo.com' }
  s.source           = { :git => 'https://git.wemomo.com/base/ProxyPlayerPod.git', :tag => s.name+'/'+s.version.to_s }
  s.ios.deployment_target = '8.0'
  s.static_framework = true

  s.vendored_frameworks = 'framework/MMMediaProxyOnly.framework'

  s.dependency "MDLog"

end
