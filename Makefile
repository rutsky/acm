# Makefile
# Some common tasks for whole project.
# Vladimir Rutsky <altsysrq@gmail.com>
# 20.05.2009

all:
	@echo "Read Makefile contents for details of usage."

public:
	git push git@github.com:rutsky/acm.git master
	git push git@gitorious.org:rutsky/acm.git master

update:	
	git fetch origin
	git merge origin/master

clean-light:
	find . -name '*.o' -exec rm '{}' \;
	find . -wholename '*.gch/c++' -exec rm '{}' \;

archive:
	tar -cf ../acm_`date +%F_%H-%M-%S`.tar ./
