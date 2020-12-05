.PHONY: start
start:
	@eval $(docker-machine env)
	@docker-compose up -d 
	@docker exec -it bharrold_lemipc bash

.PHONY: enter
enter:
	@eval $(docker-machine env)
	@docker exec -it bharrold_lemipc bash

default_goal: enter
