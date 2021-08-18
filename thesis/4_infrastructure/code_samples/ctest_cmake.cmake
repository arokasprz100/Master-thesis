# Konfiguracja procesu budowania biblioteki statycznej fifo-lib
ggss_build_static_library(
    TARGET_NAME "fifo"
)

# Konfiguracja procesu budowania testów jednostkowych dla 
# biblioteki fifo-lib.
ggss_setup_tests (
    TARGET_NAME "fifo"
)
