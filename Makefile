.PHONY: build

build:
	@for i in `ls`; do \
		if [ -d "$$i" ]; then \
			cd $$i && make; \
			cd ..; \
		fi; \
	done;