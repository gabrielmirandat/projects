import pexpect

child = pexpect.spawn("./executable")
child.expect("clara!")
print child.read
