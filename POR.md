Program of Record Mini-Specifications Sheet


Purpose: A CLI TCP Scanner used for a single-target IPV$/IPV6 Target to scan and reporting open ports and basic service banner if available

Opertaional Constraints: 
    -Timeouts per port
    -Max Concurrency
    -Acceptable Error Behavior (DNS faliures, invalid CDIR, partial scan reporting)

Inputs/Outputs:
    -Precise CLI options and formats.
    -Output Format human-readable 
        [Stretch Goal]: C# webpage with rendered UI for results
    
Defense Sector Specific goals:
    -No undefined behavior in C
    -Deterministic behavior only
    -Traceable requirements (tests if any)

Project Modules:
    -Rigid and secure CLI parser with clean validation mechanics
    -Target Enumerator turning single IP or CIDR into a sequence of addresses
    -Scanner Core: Bounded timeouts with TCP connections. Clear and legible port status
    -[Stretch Goal] Service Identifier: Attempts small banner read with timeout. Producing clear and legible report
    -[Stretch Goal] Service Identifier: Match ports against a fixed table to determine serivce type i.e 80 -> http, 20 -> SSH
    Reporter: Deterministic on find, structuered output. [Stretch Goal] C# web UI

    Definitive Data Flows and Lmits:
    -Explicit max ports per batch. maximum concurrent attempts. maximum banner size
    -clear error codes/enums instead of ad-hoc integers.

    Faliure modes:
        -What happens if DNS hangs?
            TTL kill attempt
        -What if the network is down or unreachable?
            TTL kill attempt
        -Avoiding blocking forever on connect()? 
            TTL kill attempt
    
    Defense Standards:
        -No recursion, no dynamic memory
        -Avoid obscure macros : 'goto'
        -Prefer small single purpose functions with clear side-effects
        -Always check return values from libraries and system calls
        -Carefully and rigidly validate CLI input
        -Absolutely no undefined behavior: all variables initialized, bounds checked arrays only

    In code documentation standards:
        -All functions have inputs outputs descriptions & faliure modes
        -Inherit MIRSA C 2023/ 2025 rules for coding