#include <assert.h>
#include <stdint.h>
#include <string.h>

#include "fsm.h"
#include "log.h"

int main(void) {
  log_set_level(LOG_DEBUG);

  enum example_state_id_t { START = 1, ONE, TWO, STOP, STATE_COUNT };
  enum example_trigger_id_t { NEXT = 1, PREV };

  fsm_state_table_t fsm = {
      [START] =
          (fsm_state_map_t){
              [NEXT] = ONE,
          },
      [ONE] =
          (fsm_state_map_t){
              [NEXT] = TWO,
              [PREV] = START,
          },
      [TWO] =
          (fsm_state_map_t){
              [PREV] = ONE,
              [NEXT] = STOP,
          },
      [STOP] =
          (fsm_state_map_t){
              [PREV] = TWO,
          },
  };

  fsm_state_id_t current_state = START;

  while (current_state != STOP) {

    switch (current_state) {
    case START:
      log_info("START STATE");
      fsm_send(fsm, NEXT, &current_state);
      break;
    case ONE:
      log_info("STATE ONE");
      fsm_send(fsm, NEXT, &current_state);
      break;
    case TWO:
      log_info("STATE TWO");
      fsm_send(fsm, NEXT, &current_state);
      break;
    default:
      break;
    }
  }

  return 0;
}
