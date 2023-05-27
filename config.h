
#define LEADER_NO_TIMEOUT
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 10000

#define FLOW_ONESHOT_TERM 10000
#define FLOW_ONESHOT_WAIT_TERM 10000
#define FLOW_COUNT 8
#define FLOW_LAYERS_COUNT 5

// Layout macros
#ifndef __ASSEMBLER__
#	include "layout.h"
#	include "layers.h"
#endif
