import smtplib
#from smtplib import SMTP
#from email.mime.text import MIMEText

smtp_hostname = 'smtp.gmail.com:587'

smtp_username = 'bk.ahn@aranetworks.com'
smtp_password = 'skatnr17'

def prompt(prompt):
	return input(prompt).strip()

def sendmail(text):
	# fromaddr = prompt("From: ")
	toaddrs = prompt("to: ").split()
	print ("Enter message, end with ^Z:")

	# Add the From: and To: headers at the start!
	msg = ("From: %s\r\nTo: %s\r\n\r\n"
		% (smtp_username, ", ".join(toaddrs)))
	#while 1:
	#	try:
	#		line = input()
	#	except EOFError:
	#		break
	#	if not line:
	#		break;
	#	msg = msg + line
	msg = msg + text

	print ("Message length is " + repr(len(msg)))

	#SMTP.connect('smtp.gmail.com', '587')
	#SMTP.login('bk.ahn@aranetworks.com', 'skatnr17')
	#SMTP.sendmail(fromaddr, toaddrs, msg)
	#SMTP.quit()
	#def finish(self):
	server = smtplib.SMTP(smtp_hostname)
	server.set_debuglevel(1)

	server.ehlo()
	server.starttls()
	server.ehlo()
	server.login(smtp_username, smtp_password)

	server.sendmail(smtp_username, toaddrs, msg)
	server.close()
				
	#server.sendmail(fromaddr, toaddrs, msg)
	#server.quit()
