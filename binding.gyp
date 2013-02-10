{
	'targets': [{
		'target_name' : 'shell',
		'sources'     : [ 'execSync.cc' ],
		'cflags'      : [ '-std=c++0x' ],
		'libraries'   : [ '-lboost_iostreams' ],
		'conditions'  : [
			['OS=="mac"', {
				'xcode_settings' : {
					'OTHER_CFLAGS': [
						'-std=c++0x',
					],
				},
			},],
		],
	},],
}
