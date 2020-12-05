.PHONY: start
start:
	@docker-compose up -d 
	@docker exec -it bharrold_lemipc bash

.PHONY: enter
enter:
	@docker exec -it bharrold_lemipc bash

default_goal: enter
