if [ "$1" = "debug" ] 
then
	build/unix/debug/tutorial
fi

if [ "$1" = "release" ]
then
	build/unix/release/tutorial
fi
