Pod::Spec.new do |s|

  s.name         = "ObjCWeb3jsLib"

  s.version      = "0.1.6"

  s.summary      = "Library wrap of web3.js"

  s.description  = "frameworks of web3js for iOS"

  s.homepage     = "https://github.com/ObjCWeb3js/ObjCWeb3jsLib"

  s.license      = "MIT"

  s.author       = { "ObjCWeb3js" => "ObjCWeb3js@gmail.com" }

  s.platform     = :ios, "9.0"

  s.source       = { :https => "http://github.com/ObjCWeb3js/ObjCWeb3jsLib.git", :tag => "#{s.version}" }

  s.vendored_frameworks = "ObjCWeb3js.framework"

  s.resource = 'Resources/web3js.bundle','Resources/contracts.bundle'

  s.requires_arc = true


end
